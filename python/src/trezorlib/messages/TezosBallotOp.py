# Automatically generated by pb2py
# fmt: off
from .. import protobuf as p

if __debug__:
    try:
        from typing import Dict, List  # noqa: F401
        from typing_extensions import Literal  # noqa: F401
        EnumTypeTezosBallotType = Literal[0, 1, 2]
    except ImportError:
        pass


class TezosBallotOp(p.MessageType):

    def __init__(
        self,
        *,
        source: bytes = None,
        period: int = None,
        proposal: bytes = None,
        ballot: EnumTypeTezosBallotType = None,
    ) -> None:
        self.source = source
        self.period = period
        self.proposal = proposal
        self.ballot = ballot

    @classmethod
    def get_fields(cls) -> Dict:
        return {
            1: ('source', p.BytesType, None),
            2: ('period', p.UVarintType, None),
            3: ('proposal', p.BytesType, None),
            4: ('ballot', p.EnumType("TezosBallotType", (0, 1, 2)), None),
        }
