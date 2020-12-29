# Automatically generated by pb2py
# fmt: off
from .. import protobuf as p

from .LiskDelegateType import LiskDelegateType
from .LiskMultisignatureType import LiskMultisignatureType
from .LiskSignatureType import LiskSignatureType

if __debug__:
    try:
        from typing import Dict, List  # noqa: F401
        from typing_extensions import Literal  # noqa: F401
    except ImportError:
        pass


class LiskTransactionAsset(p.MessageType):

    def __init__(
        self,
        *,
        votes: List[str] = None,
        signature: LiskSignatureType = None,
        delegate: LiskDelegateType = None,
        multisignature: LiskMultisignatureType = None,
        data: str = None,
    ) -> None:
        self.votes = votes if votes is not None else []
        self.signature = signature
        self.delegate = delegate
        self.multisignature = multisignature
        self.data = data

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('signature', LiskSignatureType, None),
            2: ('delegate', LiskDelegateType, None),
            3: ('votes', p.UnicodeType, p.FLAG_REPEATED),
            4: ('multisignature', LiskMultisignatureType, None),
            5: ('data', p.UnicodeType, None),
        }
